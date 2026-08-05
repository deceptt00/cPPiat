#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		const std::string	getName()           const;
		bool				isSigned()           const;
		int					getGradeToSign()     const;
		int					getGradeToExecute()  const;

		void beSigned(const Bureaucrat &b);

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
