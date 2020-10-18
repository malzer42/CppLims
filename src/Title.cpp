/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Title.cpp
 * Author: pamulamba
 * 
 * Created on 29 juin 2020, 22 h 22
 */

#include "Title.h"

Title::Title(const std::string& program, const std::string& release) : program_(program), release_(release) {
    std::cout << '\n' << getProgram() << '\t' << getRelease() << '\n';
}

const std::string& Title::getProgram()const{
    return program_;
}

const std::string& Title::getRelease()const{
    return release_;
}

void Title::setProgram(const std::string& program){
    program_ = program;
}

void Title::setRelease(const std::string& release){
    release_ = release;
}

