#ifndef DELETE_ELEMENT_H
#define DELETE_ELEMENT_H

#include "command.h"

namespace Commands {

    class DeleteElement : public Command
    {
    private:
    public:
        DeleteElement(std::vector<Parser::Token> command_data);
        void Execute() const override;

    };

}


#endif // !DELETE_ELEMENT_H