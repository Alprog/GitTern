
#pragma once

#include <string>

template <class ClassT>
class BasePrettyField
{
public:
    std::string format;

    virtual void apply(ClassT* instance, std::string output) = 0;
};

template <class ClassT, class FieldT>
class PrettyField : public BasePrettyField<ClassT>
{
public:
    using PointerToMember = FieldT ClassT::*;
    using Converter = FieldT(*)(std::string);

private:
    PointerToMember pointerToMember;
    Converter converter;

public:
    PrettyField(PointerToMember pointerToMember, std::string format, Converter converter)
    {
        this->pointerToMember = pointerToMember;
        this->format = format;
        this->converter = converter;
    }

    virtual void apply(ClassT* instance, std::string output) override
    {
        instance->*pointerToMember = converter(output);
    }
};
