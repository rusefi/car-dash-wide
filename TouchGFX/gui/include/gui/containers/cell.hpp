#ifndef CELL_HPP
#define CELL_HPP

#include <gui_generated/containers/cellBase.hpp>

class cell : public cellBase
{
public:
    cell();
    virtual ~cell() {}

    virtual void initialize();
    virtual void setValues(uint8_t cellID);
protected:
};

#endif // CELL_HPP
