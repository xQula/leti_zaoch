//
// Created by xqula on 24.06.24.
//

#include "manager.h"
#include "task/taskbase.h"
#include "utils/random.h"

department::Manager::Manager(QObject *parent):
    Worker("../log.txt", parent),
    m_settingDepartment(std::make_unique<SettingDepartment>()),
    m_timer(std::make_unique<QTimer>(nullptr)),
    m_countTime(0)
{
    m_settingDepartment->m_maxDesigners = 4;
    m_settingDepartment->m_executionTime = 10;
    m_settingDepartment->m_maxTasksPriority = 2;
    m_settingDepartment->m_maxTasksWeak = 8;
    for(int i = 0; i < m_settingDepartment->m_maxTasksPriority; ++i) {
        m_orderTasksPriority.emplace_back(true, "PRIORITY " +std::to_string(i));
    }
    for(int i = 0; i < m_settingDepartment->m_maxTasksWeak; ++i) {
        m_orderTasksWeak.emplace_back(false, "WEAK " +std::to_string(i));
    }
    for(int i = 0; i < m_settingDepartment->m_maxDesigners; ++i) {
        m_designers.push_back(std::make_unique<Designer>(std::to_string(i + 1), nullptr));
        connect(m_designers.back().get(), &Designer::finishTask, this, [this, i](const task::TaskBase &task){
            if(i == m_settingDepartment->m_maxDesigners - 1) {
                return;
            }
            if(task.get_priority()) {
                m_queueTasks.push_front({task, i});
           }else {
                m_queueTasks.push_back({task, i});
           }
        });
    }
    m_timer->start(200);
    connect(m_timer.get(), &QTimer::timeout, this, [this](){
        this->m_countTime += 1;
        if(this->m_countTime == this->m_settingDepartment->m_executionTime) {
            m_countTime = 0;
            if(m_orderTasksPriority.empty() && m_orderTasksWeak.empty()) {
                write("Manager: No tasks");
                return;
            }
            if(m_orderTasksPriority.empty()) {
                this->m_designers.front()->setTask(m_orderTasksWeak.back());
                m_orderTasksWeak.pop_back();
                return;
            }
            if(m_orderTasksWeak.empty()) {
                this->m_designers.front()->setTask(m_orderTasksPriority.back());
                m_orderTasksPriority.pop_back();
                return;
            }
            if(utils::Random::random(0,1)) {
                write("Manager: Start new task designer 1 " + m_orderTasksPriority.back().get_name());
                this->m_designers.front()->setTask(m_orderTasksPriority.back());
                m_orderTasksPriority.pop_back();
            }else {
                write("Manager: Start new task designer 1 " + m_orderTasksWeak.back().get_name());
                this->m_designers.front()->setTask(m_orderTasksWeak.back());
                m_orderTasksWeak.pop_back();
            }
        }
        if(not m_queueTasks.empty()) {
            write("Manager: Start new task designer " +  std::to_string(m_queueTasks.front().indexDesigner + 2) + " " + m_queueTasks.front().m_task.get_name());
            m_queueTasks.front().m_task.reset_execution_time();
            m_queueTasks.front().m_task.set_status(task::TASK_STATUS::CREATED);
            m_designers[m_queueTasks.front().indexDesigner + 1]->setTask(m_queueTasks.front().m_task);
            m_queueTasks.pop_front();
        }
    });
}
