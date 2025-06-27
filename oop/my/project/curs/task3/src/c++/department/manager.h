//
// Created by xqula on 24.06.24.
//

#pragma once
#include "worker.h"
#include "department/designer.h"
#include "deque"
#include "vector"
#include "memory"
#include "QTimer"

namespace department {

    struct SettingDepartment {
        int m_maxDesigners;
        int m_executionTime;
        int m_maxTasksPriority;
        int m_maxTasksWeak;
    };

    struct TaskData {
        task::TaskBase m_task;
        int indexDesigner;
    };

    class Manager : public Worker{
        Q_OBJECT
    public:
        explicit Manager(QObject *parent = nullptr);
        ~Manager() override = default;
    private:
        std::vector<std::unique_ptr<Designer>> m_designers;
        std::unique_ptr<SettingDepartment> m_settingDepartment;
        std::unique_ptr<QTimer> m_timer;
        int m_countTime;
        std::deque<TaskData> m_queueTasks;
        std::vector<task::TaskBase> m_orderTasksPriority;
        std::vector<task::TaskBase> m_orderTasksWeak;
    };
}
