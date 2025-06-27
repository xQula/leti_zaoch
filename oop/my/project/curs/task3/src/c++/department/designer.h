//
// Created by xqula on 24.06.24.
//

#pragma once
#include "worker.h"
#include "task/taskbase.h"
#include "deque"
#include "memory"
#include "string"
#include "QTimer"
#include "QObject"

namespace department {
    class Designer: public Worker {
        Q_OBJECT
    public:
        explicit Designer(std::string name, QObject *parent = nullptr);
        auto setTask(const task::TaskBase &task) -> void;
        [[nodiscard]] auto getName() const -> std::string;
        ~Designer() override = default;
    signals:
        void finishTask(const task::TaskBase &task);
    private:
        std::unique_ptr<QTimer> m_timer;
        int m_executionTime;
        std::deque<task::TaskBase> m_tasks;
        std::string m_name;
    };
}
