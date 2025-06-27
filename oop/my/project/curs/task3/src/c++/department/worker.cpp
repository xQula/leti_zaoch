//
// Created by xqula on 24.06.24.
//

#include "worker.h"

Worker::Worker(std::string name_file, QObject *parent):
    QObject(parent),
    m_writer(std::make_unique<utils::Writer>(std::move(name_file)))
{
}

auto Worker::write(const std::string_view txt) const -> void {
    m_writer->write(txt);
}
