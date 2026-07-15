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

		// Getters
		const std::string	&getName()            const;
		bool				isSigned()            const;
		int					getGradeToSign()      const;
		int					getGradeToExecute()   const;

		// Sign
		void beSigned(const Bureaucrat &b);

		// Execute — pure virtual: each concrete form defines its action
		virtual void execute(Bureaucrat const &executor) const = 0;

		// Nested exceptions
		class GradeTooHighException : public std::exception {
			public: virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public: virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public: virtual const char *what() const throw();
		};

	protected:
		// Helper for concrete classes: checks signed + grade before acting
		void checkExecution(Bureaucrat const &executor) const;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
