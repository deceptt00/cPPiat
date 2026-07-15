#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;  // forward declaration

class Form
{
	public:
		Form();
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		// Getters
		const std::string	&getName()           const;
		bool				isSigned()           const;
		int					getGradeToSign()     const;
		int					getGradeToExecute()  const;

		// Actions
		void beSigned(const Bureaucrat &b);

		// Nested exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
