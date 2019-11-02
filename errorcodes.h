#ifndef ERRORCODES_H
#define ERRORCODES_H

#endif // ERRORCODES_H


string ErrorCodes(int error)
{
    switch (error)
    {
    case 0:
        return "Operation completed successfully";
    case -1:
        return "Comunication error";
    case -2:
        return "Unspecfied error";

    }
}
