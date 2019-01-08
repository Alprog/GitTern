
#pragma once

#include <string>

template <class DataT>
class BasePrettyField
{
public:
    std::string format;
    virtual void apply(DataT* instance, std::string output) = 0;
};

template <class DataT, class FieldT>
class PrettyField : public BasePrettyField<DataT>
{
public:
    using PointerToMember = FieldT DataT::*;

private:
    PointerToMember pointerToMember;

public:
    PrettyField(PointerToMember pointerToMember, std::string format)
    {
        this->pointerToMember = pointerToMember;
        this->format = format;
    }

    virtual void apply(DataT* instance, std::string output) override
    {
        instance->*pointerToMember = output;
    }
};
