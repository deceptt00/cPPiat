#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		const std::string	&getName()            const;
		bool				isSigned()            const;
		int					getGradeToSign()      const;
		int					getGradeToExecute()   const;

		void beSigned(const Bureaucrat &b);

		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public: virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public: virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public: virtual const char *what() const throw();
		};

		const std::string	_name;
	protected:
		void checkExecution(Bureaucrat const &executor) const;

	private:
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
