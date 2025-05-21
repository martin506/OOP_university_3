#ifndef USECASE_H
#define USECASE_H

template <typename Port, typename Result>
class UseCase {
public:
    virtual ~UseCase() = default;
    virtual Result execute(Port parameter) = 0;
};

#endif
