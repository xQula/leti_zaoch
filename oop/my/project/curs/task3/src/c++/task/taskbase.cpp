//
// Created by xqula on 24.06.24.
//

#include "taskbase.h"

task::TaskBase::TaskBase(const bool priority, std::string name) :
    m_priority(priority),
    m_status(TASK_STATUS::CREATED),
    m_executionTime(0),
    m_name(std::move(name))
{
}

task::TaskBase::~TaskBase() = default;

auto task::TaskBase::get_priority() const -> bool {
    return m_priority;
}

auto task::TaskBase::get_status() const -> TASK_STATUS {
    return m_status;
}

auto task::TaskBase::get_executionTime() const -> int {
    return m_executionTime;
}

auto task::TaskBase::get_name() const -> std::string {
    return m_name;
}

auto task::TaskBase::set_status(const TASK_STATUS status) -> void {
    m_status = status;
}

auto task::TaskBase::up_execution_time() -> void {
    ++m_executionTime;
}

auto task::TaskBase::reset_execution_time() -> void {
    m_executionTime = 0;
}
