//    Ali Haidar, Bran Kang, Blake Brown
//    CS303 Project 1
//    3/24/2019




#include <iostream>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

class Calculator
{
public:
	void Open(ifstream& f, string afile);
	void Process(ifstream& f);
	void Execute();
	void Display();
	void DisplayOp();

private:
	stack <int> valStack;
	stack <char> opStack;
};


int main()
{
	Calculator Infix;
	ifstream INFILE;
	string filename;

	cout << "Enter filename to open: ";
	cin >> filename;

	Infix.Open(INFILE, filename);
	Infix.Process(INFILE);

	system("Pause");

	return 0;
}

void Calculator::Open(ifstream& f, string afile)
{

	f.open(afile.c_str());

	if (f.fail())
	{
		cout << "Error: File not Opened!" << "\n";
		cout << "Exiting Program!" << "\n";
		system("Pause");
		exit(1);
	}
}

void Calculator::Process(ifstream& f)
{
	int result;
	string infixExpr;
	char achar;
	
	while (f && f.peek() != EOF)
	{
		getline(f, infixExpr);
	}

	for (int i = 0; i < infixExpr.length(); i++)
	{
		achar = infixExpr[i];

		if (isdigit(achar))
		{
			valStack.push(achar);
			cout << "Pushed into valStack: " << achar << "\n";
		}

		else
			switch (achar)
			{

			case('('):
			{
				opStack.push(achar);
				cout << "Pushed into opStack: " << achar << "\n";

				break;
			}

			case('*'):

			{
				if (opStack.empty())
				{
					opStack.push(achar);
					cout << "Pushed into opStack: " << achar << "\n";
				}

				else if (achar > opStack.top())
				{
					opStack.push(achar);
					cout << "Pushed into opStack: " << achar << "\n";
				}

				else
				{
					while (!opStack.empty() && achar <= opStack.top())
					{
						Execute();
						opStack.push(achar);
						cout << "Pushed into opStack: " << achar << "\n";
					}
				}

				break;

			}//end if



			case('+'):
			{

				if (opStack.empty())
				{
					opStack.push(achar);
					cout << "Pushed into opStack: " << achar << "\n";
				}



				else if (achar > opStack.top())
				{
					opStack.push(achar);
					cout << "Pushed into opStack: " << achar << "\n";
				}

				else
				{
					while (!opStack.empty() && achar <= opStack.top())
					{
						Execute();
						opStack.push(achar);
						cout << "Pushed into opStack: " << achar << "\n";
					}
				}

				break;

			}//end if

			case('-'):
			{

				if (opStack.empty())
				{
					opStack.push(achar);
					cout << "Pushed into opStack: " << achar << "\n";
				}


				else if (achar > opStack.top())
				{
					opStack.push(achar);
					cout << "Pushed into opStack: " << achar << "\n";
				}

				else
				{
					while (!opStack.empty() && achar <= opStack.top())
					{
						Execute();
						opStack.push(achar);
						cout << "Pushed into opStack: " << achar << "\n";
					}
				}

			}//end if

			break;


			case('/'):
			{

				if (opStack.empty())
				{
					opStack.push(achar);
					cout << "Pushed into opStack: " << achar << "\n";
				}


				else if (achar > opStack.top())
				{
					opStack.push(achar);
					cout << "Pushed into opStack: " << achar << "\n";
				}

				else
				{
					while (!opStack.empty() && achar <= opStack.top())
					{
						Execute();
						opStack.push(achar);
						cout << "Pushed into opStack: " << achar << "\n";
					}
				}

			}//end if

			break;


			case('^'):
			{
				if (opStack.empty())
				{
					opStack.push(achar);
					cout << "Pushed into opStack: " << achar << "\n";
				}


				else if (achar > opStack.top())
				{
					opStack.push(achar);
					cout << "Pushed into opStack: " << achar << "\n";
				}
		
				else
				{
					while (!opStack.empty() && achar <= opStack.top())
					{
						Execute();
						opStack.push(achar);
						cout << "Pushed into opStack: " << achar << "\n";
					}
				}

			}//end if

			break;


			case(')'):
			{
				while (opStack.top() != '(')
				{
					Execute();
					opStack.pop();
					break;
				}
			}
			}//end switch
	}//end for



	while (!opStack.empty())
	{
		Execute();
		result = valStack.top();
	}

}//end of Process()

void Calculator::Execute()
{
	int operand2, operand1, result;
	char op;


	operand2 = valStack.top();
	valStack.pop();


	operand1 = valStack.top();
	valStack.pop();


	op = opStack.top();
	opStack.pop();


	switch (op)
	{
	case('^'):
	{
		result = operand1 ^ operand2;
		valStack.push(result);



		break;
	}


	case('*'):
	{
		result = operand1 * operand2;


		cout << "values" << operand1 << " " << operand2;
		system("pause");


		valStack.push(result);
		cout << "Valstack has: ";
		Display();
		system("pause");
		cout << "Result for * op is: " << result;
		break;
	}


	case('/'):
	{
		if (operand2 == '0')
			cout << "Division by zero error!";


		else
			result = operand1 / operand2;
		valStack.push(result);
		break;
	}


	case('+'):
	{
		result = operand1 + operand2;
		cout << "Result:" << result;
		valStack.push(result);
		break;
	}

	case('-'):
	{
		result = operand1 - operand2;
		valStack.push(result);
		break;
	}


	}//end switch
}

void Calculator::Display()
{
	while (!valStack.empty())
	{
		cout << valStack.top();
		valStack.pop();
	}
}

void Calculator::DisplayOp()
{
	while (!opStack.empty())
	{
		cout << opStack.top();
		opStack.pop();
	}
}