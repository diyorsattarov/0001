#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <string>

class Foo
{
private:
    int fooId = 0;
public:
    virtual ~Foo() = default;

    virtual int getFooId() const
    {
        return fooId;
    }

    virtual std::string getFooName() const
    {
        return "DefaultFoo";
    }

    virtual double getFooValue() const
    {
        return 0.0;
    }

    virtual void setFooId(int id)
    {
        if(id > 0)
        {
            this->fooId = id;
        }
    }

    virtual void setFooName(const std::string& name)
    {
    }

    virtual void setFooValue(double value)
    {
    }

    virtual void printFooInfo() const
    {
        std::cout << "Foo ID: " << getFooId() << std::endl;
        std::cout << "Foo Name: " << getFooName() << std::endl;
        std::cout << "Foo Value: " << getFooValue() << std::endl;
    }
};

class Bar : public Foo
{
private:
    double barValue;

public:
    Bar() : barValue(0.0)
    {
    }

    Bar(int id, const std::string& name, double fooValue, double barValue)
        : Foo(), barValue(barValue)
    {
    }

    virtual double getBarValue() const
    {
        return barValue;
    }

    virtual void setBarValue(double value)
    {
        barValue = value;
    }

    virtual void printBarInfo() const
    {
        std::cout << "Bar Value: " << barValue << std::endl;
    }

    virtual std::string getFooName() const override
    {
        return "Bar: " + Foo::getFooName();
    }

    virtual void printFooInfo() const override
    {
        Foo::printFooInfo();
        std::cout << "Bar Value: " << barValue << std::endl;
    }
};
