//
// Created by xqula on 24.06.24.
//

#pragma once
#include "string"

namespace task {
    enum class TASK_STATUS {
        CREATED,
        RUNNING,
        FINISHED
    };
    class TaskBase {
    public:
        explicit TaskBase(bool priority, std::string name);
        virtual ~TaskBase();
        [[nodiscard]] auto get_priority() const -> bool;
        [[nodiscard]] auto get_status() const -> TASK_STATUS;
        [[nodiscard]] auto get_executionTime() const -> int;
        [[nodiscard]] auto get_name() const -> std::string;
        auto set_status(TASK_STATUS status) -> void;
        auto up_execution_time() -> void;
        auto reset_execution_time() -> void;
    private:
        bool m_priority;
        TASK_STATUS m_status;
        int m_executionTime;
        std::string m_name;
    };
}
