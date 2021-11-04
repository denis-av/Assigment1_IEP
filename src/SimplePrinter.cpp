#include<iostream>

class SimplePrinter{
    protected:
        int capacityToPrintPerMinute;
        bool scanner;
        double colorInkPercentage, blackInkPercentage, energyConsumedPerHour, colorTakePerPage , blackTakePerPage ;

    public:/*
        SimplePrinter()  {
            colorInkPercentage = 50;
            blackInkPercentage = 50;
            capacityToPrintPerMinute = 15;
            scanner = false;
            energyConsumedPerHour = 75.5;
        }*/

        //Parameterized Constructors
        SimplePrinter(double colorInkPercentage = 50, double blackInkPercentage = 50, int capacityToPrintPerMinute = 15,bool scanner = false , double energyConsumedPerHour = 75.5, double colorTakePerPage = 0.4, double blackTakePerPage = 0.3) :
            colorInkPercentage(colorInkPercentage),
            blackInkPercentage(blackInkPercentage),
            capacityToPrintPerMinute(capacityToPrintPerMinute),
            scanner(scanner),
            energyConsumedPerHour(energyConsumedPerHour),
            colorTakePerPage(colorTakePerPage),
            blackTakePerPage(blackTakePerPage)
         {}

        //Copy Constructor
        SimplePrinter(const SimplePrinter& printerOne) :
            colorInkPercentage(printerOne.colorInkPercentage),
            blackInkPercentage(printerOne.blackInkPercentage),
            capacityToPrintPerMinute(printerOne.capacityToPrintPerMinute),
            scanner(printerOne.scanner),
            energyConsumedPerHour(printerOne.energyConsumedPerHour),
            colorTakePerPage(printerOne.colorTakePerPage),
            blackTakePerPage(printerOne.blackTakePerPage)
        {}


        SimplePrinter& operator = (const SimplePrinter &simpl){
            this->colorInkPercentage = simpl.colorInkPercentage;
            this->blackInkPercentage = simpl.blackInkPercentage;
            this->capacityToPrintPerMinute = simpl.capacityToPrintPerMinute;
            this->scanner = simpl.scanner;
            this->energyConsumedPerHour = simpl.energyConsumedPerHour;
            return *this;
        } 

        void printDetails(){
            std::cout << "Color ink percentage: "<< colorInkPercentage << "%" << std::endl;
            std::cout << "Black ink percentage: "<< blackInkPercentage << "%" << std::endl;
            std::cout << "Maximum number of pages printed per minute: "<< capacityToPrintPerMinute << std::endl;
            std::cout << "Scanner supported: ";
            if(scanner == true) std::cout<< "true" << std::endl;
            else std::cout<< "false" << std::endl;
            std::cout << "Energy consumed per hour: "<< energyConsumedPerHour <<std::endl;
            std::cout << "Color ink take per page: "<< colorTakePerPage << "%" << std::endl;
            std::cout << "Energy consumed per hour: "<< blackTakePerPage << "%" << std::endl;
        }

        void addScanner(){
            if(scanner == true){
                    std::cout << std::endl << "This printer already has a scanner." << std::endl<< std::endl;
            } 
            else{
                scanner= true;
                std::cout << std::endl << "Scanner successfully added." << std::endl<< std::endl;
            }
        }

        void rechargeInk(){
            if(colorInkPercentage == 100) {
                std::cout << std::endl << "Color ink is already full.";
            }else {
                colorInkPercentage = 100;
                std::cout << std::endl << "Color ink successfully recharged.";
            }

            if(blackInkPercentage == 100) {
                std::cout << std::endl << "Black ink is already full.";
            }else {
                blackInkPercentage = 100;
                std::cout << std::endl << "Black ink successfully recharged.";
            }
            std::cout << std::endl;
        }

        int calculateNoPagesToPrintWithColorInk(){
            return colorInkPercentage/colorTakePerPage;
        }

        int calculateNoPagesToPrintWithBlackInk(){
            return blackInkPercentage/blackTakePerPage;
        }
};

class AdvancedPrinter: public SimplePrinter{
    protected:
            bool wirless;
    public:
        //Parameterized Constructors
        AdvancedPrinter(double colorInkPercentage = 100, double blackInkPercentage = 100, int capacityToPrintPerMinute = 50,bool scanner = true, double energyConsumedPerHour = 27.45, bool wirless = true, double colorTakePerPage = 0.3, double blackTakePerPage = 0.2) : 
        SimplePrinter(colorInkPercentage,blackInkPercentage,capacityToPrintPerMinute,scanner,energyConsumedPerHour,colorTakePerPage,blackTakePerPage),
        wirless(wirless)
        {}

        AdvancedPrinter(const AdvancedPrinter &adv):
        SimplePrinter(adv),
        wirless(wirless)
        {}

        void printDetails(){
            SimplePrinter::printDetails();
            std::cout << "Wirless: ";
            if(wirless == true) std::cout<< "true" << std::endl << std::endl;
            else std::cout<< "false" << std::endl << std::endl;
        }
};

class SuperAdvancedPrinter : public SimplePrinter{
    protected:
        bool holeMaking = true;
        bool wirless = true;
        int numberHoles;
        int uniqueID;
        int length;
        int width;

    private:
        SuperAdvancedPrinter(const SuperAdvancedPrinter&){}      
        SuperAdvancedPrinter& operator=(const SuperAdvancedPrinter&);

    public:
        SuperAdvancedPrinter(double colorInkPercentage = 100, double blackInkPercentage = 100, int capacityToPrintPerMinute = 75, double energyConsumedPerHour = 12.5, bool scanner = true, int numberHoles = 2, int length = 45, int width = 30,double colorTakePerPage = 0.2, double blackTakePerPage = 0.1) :
        SimplePrinter(colorInkPercentage,blackInkPercentage,capacityToPrintPerMinute,scanner,energyConsumedPerHour, colorTakePerPage, blackTakePerPage),
        numberHoles(numberHoles),
        length(length),
        width(width),
        uniqueID(rand() % 9999)
        {}


        void printDetails(){
            std::cout << "Unique ID: " << uniqueID << std::endl;
            SimplePrinter::printDetails();
            std::cout << "Wirless: true" << std::endl;
            std::cout << "Hole making: true" << std::endl;
            std::cout << "Number of holes per page: " << numberHoles << std::endl << std::endl;
        }
};


int main(){
    SimplePrinter s0;
    std::cout << "Printer 0:" << std::endl;
    s0.printDetails();
    SimplePrinter s1(75,50,20,true,45.5);
    SimplePrinter s2(s1);
    std::cout << std::endl << std::endl;
    std::cout << "Printer 1:" << std::endl;
    s1.printDetails();
    std::cout << std::endl << std::endl;
    std::cout << "Printer 2:" << std::endl;
    s2.printDetails();
    std::cout << std::endl << std::endl;
    s1.rechargeInk();
    s2.addScanner();
    AdvancedPrinter s3;
    std::cout << "Printer 3:" << std::endl;
    s3.printDetails();
    AdvancedPrinter s4(110,110,70,true,12,false);
    AdvancedPrinter s5(s4);
    std::cout << std::endl << std::endl;
    std::cout << "Printer 5:" << std::endl;
    s5.printDetails();
    SimplePrinter s6;
    s6 = s2;
    std::cout << std::endl << std::endl;
    std::cout << "Printer 6:" << std::endl;
    s6.printDetails();
    SuperAdvancedPrinter s7;
    std::cout << std::endl << std::endl;
    std::cout << "Printer 7:" << std::endl;
    s7.printDetails();
    SuperAdvancedPrinter s8(150,120,90,10,4,70,25);
    std::cout << std::endl << std::endl;
    std::cout << "Printer 8:" << std::endl;
    s8.printDetails();
    //SuperAdvancedPrinter s9;
    //s9=s8;
    //SuperAdvancedPrinter s9(s8); - error
    std::cout << s8.calculateNoPagesToPrintWithColorInk() << " files could be printed using blank ink by Printer 8" << std::endl;
}