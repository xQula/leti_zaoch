//
// Created by xqula on 24.06.24.
//

#include "designer.h"

department::Designer::Designer(std::string name, QObject *parent) :
    Worker( "../log.txt", nullptr),
    m_timer(std::make_unique<QTimer>(nullptr)),
    m_executionTime(5),
    m_name(std::move(name))
{
    m_timer->start(200);
    connect(m_timer.get(), &QTimer::timeout, this, [this](){
        if(!this->m_tasks.empty()) {
            m_tasks.front().set_status(task::TASK_STATUS::RUNNING);
            m_tasks.front().up_execution_time();
            if(m_tasks.front().get_executionTime() == m_executionTime) {
                m_tasks.front().set_status(task::TASK_STATUS::FINISHED);
                write("Designer " + m_name + ": Finish task " + m_tasks.front().get_name());
                emit finishTask(m_tasks.front());
                m_tasks.pop_front();
            }
        }
    });

}

auto department::Designer::setTask(const task::TaskBase &task) -> void {
    write("Designer " + m_name + ": Start new task " + task.get_name());
    if(task.get_priority()) {
        if(not m_tasks.empty()) {
            if(m_tasks.front().get_priority()) {
                const auto tmpTask = m_tasks.front();
                m_tasks.pop_front();
                m_tasks.push_front(task);
                m_tasks.push_front(tmpTask);
                return;
            }
        }
        m_tasks.push_front(task);
    } else {
        m_tasks.push_back(task);
    }
}

auto department::Designer::getName() const -> std::string {
    return m_name;
}
