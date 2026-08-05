#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();

		AForm *makeForm(const std::string &formName, const std::string &target) const;

		class UnknownFormException : public std::exception {
			public: virtual const char *what() const throw();
		};

	private:
		typedef AForm *(*FormFactory)(const std::string &target);

		static AForm *makeShrubbery(const std::string &target);
		static AForm *makeRobotomy(const std::string &target);
		static AForm *makePardon(const std::string &target);
};

#endif
