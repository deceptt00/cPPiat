#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecution(executor);

	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("ShrubberyCreationForm: could not open file " + filename);

	file << R"( &&& &&  & &&)" << std::endl;
    file << R"(      && &\/&\|& ()|/ @, &&)" << std::endl;
    file << R"(      &\/(/&/&||/& /_/)_&/_&)" << std::endl;
    file << R"(   &() &\/&|()|/&\/ '%" & ())" << std::endl;
    file << R"(  &_\_&&_\ |& |&&/&__%_/_& &&)" << std::endl;
    file << R"(&&   && & &| &| /& & % ()& /&&)" << std::endl;
    file << R"( ()&_---()&\&\|&&-&&--%---()~)" << std::endl;
    file << R"(     &&     \|||)" << std::endl;
    file << R"(             |||)" << std::endl;
    file << R"(             |||)" << std::endl;
    file << R"(             |||)" << std::endl;
    file << R"(       , -=-~  .-^- )" << std::endl;
	file.close();
	std::cout << "ShrubberyCreationForm: created file '" << filename << "'" << std::endl;
}
