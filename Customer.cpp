#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iomanip>

class Customer {
protected:
    std::string name;
    int id;
    bool freeService;
    bool fullService;

public:
  
    Customer() : id(0), freeService(false), fullService(false), name("") {}

  
    Customer(int id, bool freeService, bool fullService, const std::string& name) 
        : id(id), freeService(freeService), fullService(fullService), name(name) {}


    int getId() const {
        return id;
    }
    bool hasFreeService() const {
        return freeService;
    }
    bool hasFullService() const {
        return fullService;
    }
    std::string getName() const {
        return name;
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }
    void setFreeService(bool freeService) {
        this->freeService = freeService;
    }
    void setFullService(bool fullService) {
        this->fullService = fullService;
    }
    void setName(const std::string& name) {
        this->name = name;
    }

  
    virtual std::string getType() const = 0;

    
    virtual void display() const {
        std::cout << std::left << std::setw(20) << getType()
                  << std::setw(10) << id
                  << std::setw(20) << name 
                  << std::setw(15) << (freeService ? "Yes" : "No")
                  << std::setw(15) << (fullService ? "Yes" : "No") << std::endl;
    }

   
    virtual ~Customer() = default;
};
