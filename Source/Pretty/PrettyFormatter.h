
#pragma once

#include <vector>
#include "PrettyField.h"

template <class T>
class PrettyFormatter
{
    using Field = BasePrettyField<T>;

private:
    std::vector<Field> fields;

public:
    template <class FieldT>
    void addField(typename PrettyField<T, FieldT>::PointerToMember pointerToMember, std::string format)
    {
        fields.push_back(PrettyField<T, FieldT>(pointerToMember, format));
    }

    std::vector<T> parse(std::string text)
    {
        auto records = new std::vector<T>();


        auto lines = split(text, '\n');

        size_t i = 0;
        while (i + fields.size() < lines.size())
        {
            auto record = T();
            for (auto field : fields)
            {
                field->apply(record, lines[i++]);
            }
            records->push_back(record);
        }

        return records;
    }
};
