#include "buildings.h"

void building::AddName(string NewName)
{
//    Name = NewName;
}

void building::AddHeader(string NewHeader)
{
//    Header = Header;
}

void building::DisplayInfo()
{
    cout << "ID: " << ID << endl;
    cout << "Name: " << Name << endl;
    cout << "Header: " << Header << endl;
}

string building::GetName()
{
    return Name;
}

string building::GetHeader()
{
    return Header;
}
