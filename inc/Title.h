/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Title.h
 * Author: pamulamba
 *
 * Created on 29 juin 2020, 22 h 22
 */

#ifndef TITLE_H
#define TITLE_H

#include <string>
#include <iostream>


class Title {
public:
    Title(const std::string& program, const std::string& release);
    const std::string& getProgram()const;
    const std::string& getRelease()const;
    void setProgram(const std::string& program);
    void setRelease(const std::string& release);
    
    virtual ~Title() = default;
private:
    std::string program_;
    std::string release_;
};

#endif /* TITLE_H */

