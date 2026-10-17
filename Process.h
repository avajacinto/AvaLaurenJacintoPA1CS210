//
// Created by avaja on 10/6/2026.
//

#pragma once

#include <iostream>
#include <string>

class Process {
private:
    int pid_;
    std::string processName_;
    std::string desc_;

public:
    Process(int pid = 0, const std::string& processName = "", const std::string& desc = "") : pid_(pid), processName_(processName), desc_(desc) {
    }

    int getPID() const {
        return pid_;
    }

    std::string getProcessName() const {
        return processName_;
    }

    std::string getDesc() const {
        return desc_;
    }

    // Setters
    void setPID(int pid) {
        pid_ = pid;
    }

    void setPID(int pid) {
        pid_ = pid;
    }

    void setProcessName(const std::string& processName) {
        processName_ = processName;
    }

    void setDesc(const std::string& desc) {
        desc_ = desc;
    }

    void print() const {
        std::cout << pid_ << " " << processName_ << " " << desc_;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Process& process) {
    process.print();
    return out;
}