#include "abstract/human-model.h"

Human::Human() : name("Unknown"), surname("Unknown") {}

Human::Human(const std::string& name, const std::string& surname) : name(name), surname(surname) {}

Human::~Human() = default;
