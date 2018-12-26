
#pragma once

#include <string>

template <class DataT>
class BasePrettyField
{
public:
    std::string format;
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

    void apply(DataT* instance, std::string output)
    {
        instance.*pointerToMember = output;
    }
};
