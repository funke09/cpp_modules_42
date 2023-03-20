#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);

    std::string filename = _target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (ofs.fail()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }

    ofs << "      //\\\\      " << std::endl
        << "     //  \\\\     " << std::endl
        << "    //    \\\\    " << std::endl
        << "   //      \\\\   " << std::endl
        << "  //        \\\\  " << std::endl
        << " //          \\\\ " << std::endl
        << "//____________\\\\" << std::endl
        << "      ||      " << std::endl
        << "      ||      " << std::endl
        << "      ||      " << std::endl;

    ofs.close();

    std::cout << "Shrubbery creation form has been executed successfully by "
              << executor.getName() << "!" << std::endl;
}
