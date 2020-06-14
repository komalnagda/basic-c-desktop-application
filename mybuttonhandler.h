#ifndef MYBUTTONHANDLER_H
#define MYBUTTONHANDLER_H

#include <QObject>
#include <QDebug>

class MyButtonHandler : public QObject
{
    Q_OBJECT
    public:
        explicit MyButtonHandler(QObject *parent = 0);

    signals:
        void someSignal(QString str);

    public slots:
        void someSlot(QString str, int index);

        std::string perfectNumber(QString str){
            int sum=0;
            if (input<1){
                return "please enter a valid number greater then 1";
            }
            else{
                for(int i=1;i<=input/2;i++)
                {
                    if (input%i==0){
                        sum=sum+i;

                    }
                }
                if (sum==input){
                    return std::to_string(input) + " is a perfect number";
                }
                else{

                    return std::to_string(input)" is a not perfect number";
                }
            }
        }

        std::string factorial(QString str){
            int input = str.toInt();
            int fact=1;
            for(int i=1;i<=input;i++){
                fact=fact*i;
            }
            return std::to_string(fact);
        }

        std::string primeNumber(QString str){
            if (input==2){
                return "2 is prime number";
            }
            else if (input<2){
                return "please enter number greater then 1";
            }
            else{

                if (input%2==0){
                    return std::to_str(input) + " is not a prime number";
                }
                else{
                        for (int i=3;i<=input/2;i=i+2)
                            {
                                if (input%i==0)
                                    {
                                        return std::to_string(input) + " is not a prime number";
                                    }
                                else
                                {
                                    return std::to_string(input) + " is a prime number";
                                }
                            }
                    }
            }
        }
};

#endif // MYBUTTONHANDLER_H
