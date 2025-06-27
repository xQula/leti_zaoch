//
// Created by xqula on 24.06.24.
//

#ifndef WORKER_H
#define WORKER_H

#include "utils/writer.h"
#include "memory"
#include "string"
#include "QObject"

class Worker : public QObject {
    Q_OBJECT
public:
    explicit Worker(std::string name_file ,QObject *parent = nullptr);
    ~Worker() override = default;
    auto write(std::string_view txt) const -> void;
private:
    std::unique_ptr<utils::Writer> m_writer;
};



#endif //WORKER_H
