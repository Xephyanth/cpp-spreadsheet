#pragma once

#include "cell.h"
#include "common.h"

#include <functional>

class Sheet : public SheetInterface {
public:
    ~Sheet();
    
    void SetCell(Position pos, std::string text) override;
    
    const CellInterface* GetCell(Position pos) const override;
    CellInterface* GetCell(Position pos) override;
    
    Cell* GetCell(Position pos);
    
    void ClearCell(Position pos) override;
    
    Size GetPrintableSize() const override;
    
    void PrintValues(std::ostream& output) const override;
    void PrintTexts(std::ostream& output) const override;
    
    void Invalidate(const Position& pos);
    
private:
    std::vector<std::vector<std::unique_ptr<Cell>>> cells_;
};