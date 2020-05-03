//
// Created by Андрей Боровец on 11.04.2020.
//

#ifndef GAME_TECHPROG_EXCEPTIONS_H
#define GAME_TECHPROG_EXCEPTIONS_H


class Exception {
public:
    virtual std::string what();
};

class GameOverException : public Exception {
public:
    virtual std::string what() override;
};

class NotEnoughMoney : public Exception {
public:
    virtual std::string what() override;
};

class LowLevel : public  Exception {
public:
    virtual  std::string what() override;
};

class HasAlreadyGone : public Exception {
public:
    virtual std::string what() override;
};

class MaxLevel : public Exception {
public:
    virtual std::string what() override;
};

class InvalidArgument : public Exception {
public:
    virtual std::string what() override;
};

class NotEnougSquads : public Exception {
public:
    virtual std::string what() override;
};

class NotEnoughUnits : public Exception {
public:
    virtual std::string what() override;
};

class NoName : public Exception {
public:
    virtual std::string what() override;
};

class LongDistance : public Exception {
public:
    virtual std::string what() override;
};
#endif //GAME_TECHPROG_EXCEPTIONS_H
