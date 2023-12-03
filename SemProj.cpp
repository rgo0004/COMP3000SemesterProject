#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct chem{
    string name;
    string description;
    double properties[5]; // [Molar Mass, Melting Point, Boiling Point, Critical Temperature, Critical Pressure]
    double antoine[3]; // [A,B,C] (Coefficients for Antoine's Equation to find vapor pressure of a given species.)
};

struct stock{
    string name;
    double amountkg;
    double amountmoles;
};

class chemicalDatabase
{
    public:
        chemicalDatabase();
        void addremove();
        void getProperty();
        void vaporPressure();
        void showList();
        double stockAccess(string chemical);
    private:
        vector<chem> chems;
};

class stockRoom
{
    public:
        void addremove(chemicalDatabase &d);
        void showStock();
    private:
        vector<stock> stocks;
};


int main(){
    cout << "Welcome to your very own chemical database and chemical stock tracker!" << endl;
    chemicalDatabase d;
    stockRoom s;
    int again = 1;
    int menu = 1;
    while(again != 0){
        do{
            cout << "Enter 0 to show the menu" << endl;
            cin >> menu;
        }
        while(menu != 0);
        cout << "Enter 1 to show the list of chemicals in the database." << endl << "Enter 2 to add or remove a chemical from the database." << endl
        << "Enter 3 to retrieve a chemical property from the database." << endl << "Enter 4 to calculate the vapor pressure of a database chemical at a given temperature." << endl
        << "Enter 5 to show the chemicals in the stockroom." << endl << "Enter 6 to add or remove stock of a chemical in the stockroom" << endl 
        << "Enter 0 to quit the program." << endl;
        cin >> again;
        switch(again){
            case 1:
            d.showList();
            break;
            case 2:
            d.addremove();
            break;
            case 3:
            d.getProperty();
            break;
            case 4:
            d.vaporPressure();
            break;
            case 5:
            s.showStock();
            break;
            case 6: 
            s.addremove(d);
            break;
        }
    }
return 0;
}

chemicalDatabase::chemicalDatabase(){
    chem C1;
    C1.name = "Water";
    C1.description = "Water:\n \nChemical Formula: H2O\n \nWater is a commonly found chemical necessary for life. It is a colorless liquid at room temperature.\
    \nWater is commonly used as a polar solvent, as a reactant, and as a heat transfer utility.\
    \n \nNFPA Safety Ratings:\nHealth Hazard: 0\nFire Hazard: 0\nReactivity: 0";
    C1.properties[0] = 18.015; C1.properties[1] = 273.15; C1.properties[2] = 373.17; C1.properties[3] = 647.00; C1.properties[4] = 220.64;
    C1.antoine[0] = 5.40221; C1.antoine[1] = 1838.675; C1.antoine[2] = -31.737;

    chem C2;
    C2.name = "Benzene";
    C2.description = "Benzene:\n \nChemical Formula: C6H6\n \nBenzene is an aromatic organic molecule common in laboratory and industry. It is a colorless liquid at room temperature.\
    \nBenzene is used in industry both as a nonpolar solvent and as a raw material in the synthesis of numerous chemicals.\
    \n \nNFPA Safety Ratings:\nHealth Hazard: 2\nFire Hazard: 3\nReactivity: 0";
    C2.properties[0] = 78.11; C2.properties[1] = 278.50; C2.properties[2] = 353.30; C2.properties[3] = 562.00; C2.properties[4] = 48.90;
    C2.antoine[0] = 4.72583; C2.antoine[1] = 1660.652; C2.antoine[2] = -1.461;

    chem C3;
    C3.name = "Ethanol";
    C3.description = "Ethanol:\n \nChemical Formula: C2H6O\n \nEthanol is a common chemical found in beverages and gasoline. It is a colorless liquid at room temperature.\
    \nEthanol is commonly used as a polar solvent and reactant in labs and industry.\
    \n \nNFPA Safety Ratings:\nHealth Hazard: 2\nFire Hazard: 3\nReactivity: 0";
    C3.properties[0] = 46.07; C3.properties[1] = 159.00; C3.properties[2] = 351.50; C3.properties[3] = 514.00; C3.properties[4] = 63.00;
    C3.antoine[0] = 4.92531; C3.antoine[1] = 1432.526; C3.antoine[2] = -61.819;

    chem C4;
    C4.name = "Acrolein";
    C4.description = "Acrolein:\n \nChemical Formula: C3H4O\n \nAcrolein is a chemical used in the chemical industry and as a biocide. It is a clear yellow liquid at room temperature.\
    \nAcrolein is commonly used as a staring material in commercial production of methionine.\
    \n \nNFPA Safety Ratings:\nHealth Hazard: 4\nFire Hazard: 3\nReactivity: 0";
    C4.properties[0] = 56.06; C4.properties[1] = 185.50; C4.properties[2] = 330.00; C4.properties[3] = 527.00; C4.properties[4] = 50.66;
    C4.antoine[0] = 4.11586; C4.antoine[1] = 1167.888; C4.antoine[2] = -41.56;

    chems.push_back(C1); chems.push_back(C2); chems.push_back(C3); chems.push_back(C4);
}

void chemicalDatabase::addremove(){
    string chemical;
    int again = 1;
    int add = 0;
    int index;
    int match = 0;
    do{
        cout << "Enter the name of the chemical you would like to add or remove." << endl;
        cin >> chemical;
        for(int i=0; i<=chems.size()-1; i++){
            if(chemical == chems[i].name){
                match = 1;
                index = i;
                again = 0;
            }
        }
        if(match == 0){
            cout << "No chemical with the name " << chemical << " could be found already." << endl << "Would you like to add " << chemical << " to the database?" << endl
            << "Enter 0 for No and 1 for Yes." << endl;
                do{
                    cin >> add;
                    if(add<0 | add>1){
                        cout << "Enter 0 for No and 1 for Yes." << endl;
                    }
                }
                while(add<0 | add>1);
                if(add == 1){
                again = 0;  
                } 
        }
        else{
            again = 0;
        }
    }
    while(again == 1);
    if(add == 1){
        chem Cnew;
        Cnew.name = chemical;
        cout << "Enter the description for the chemical." << endl;
        cin.ignore();
        getline(cin,Cnew.description);
        cout << "Enter the molar mass in g/mol of the chemical." << endl;
        cin >> Cnew.properties[0];
        cout << "Enter the melting point of the chemical in Kelvin." << endl;
        cin >> Cnew.properties[1];
        cout << "Enter the boiling point of the chemical in Kelvin." << endl;
        cin >> Cnew.properties[2];
        cout << "Enter the critical temperature of the chemical in Kelvin." << endl;
        cin >> Cnew.properties[3];
        cout << "Enter the critical temperature of the chemical in Bar absolute." << endl;
        cin >> Cnew.properties[4];
        cout << "Enter the parameter A for Antoine's Equation for the chemical." << endl;
        cin >> Cnew.antoine[0];
        cout << "Enter the parameter B for Antoine's Equation for the chemical." << endl;
        cin >> Cnew.antoine[1];
        cout << "Enter the parameter C for Antoine's Equation for the chemical." << endl;
        cin >> Cnew.antoine[2];
        chems.push_back(Cnew);
        cout << "The chemical " << chemical << " has been added to the database!" << endl << endl;
    }
    if(match == 1){
        for(int k=index; k<=chems.size()-2; k++){
                        chems[k] = chems[k+1];
        }
        chems.pop_back();
        cout << chemical << " has been removed from the database." << endl << endl;
    }
}

void chemicalDatabase::showList(){
    cout << "All Chemicals in Database:" << endl;
    for(int i=0; i<=chems.size()-1; i++){
        cout << chems[i].name << endl;
    }
    cout << endl;
}

void chemicalDatabase::getProperty(){
    string chemical;
    int again = 1;
    int index = 0;
    int match = 0;
    int type;
    do{
        cout << "Enter the name of the chemical you would like to find properties for." << endl;
        cin >> chemical;
        for(int i=0; i<=chems.size()-1; i++){
            if(chemical == chems[i].name){
                match = 1;
                again = 0;
                index = i;
            }
        }
        if(match == 0){
            cout << "No chemical with the name " << chemical << " could be found." << endl << "Would you like to try again?" << endl
            << "Enter 0 for No and 1 for Yes." << endl;
                do{
                    cin >> again;
                    if(again<0 | again>1){
                        cout << "Enter 0 for No and 1 for Yes." << endl;
                    }
                }
                while(again<0 | again>1);
        }
    }
    while(again == 1);
    if(match == 1){
        cout << "Property Menu:" << endl << "Enter 0 to show the description for " << chemical << "." << endl
        << "Enter 1 to show the molar mass." << endl << "Enter 2 to show the melting point." << endl
        << "Enter 3 to show the boiling point." << endl << "Enter 4 to show the critical temperature." << endl
        << "Enter 5 to show the critical pressure." << endl << "Enter 6 to show all information." << endl;
        cin >> type;
        switch(type){
            case 0:
                cout << chems[index].description << endl;
                break;
            case 1:
                cout << "Molar Mass: " << chems[index].properties[0] << " g/mol" << endl;
                break;
            case 2:
                cout << "Melting Point: " << chems[index].properties[1] << " K" << endl;
                break;
            case 3:
                cout << "Boiling Point: " << chems[index].properties[2] << " K" << endl;
            case 4:
                cout << "Critical Temperature: " << chems[index].properties[3] << " K" << endl;
                break;
            case 5:
                cout << "Critical Pressure: " << chems[index].properties[4] << " bar" << endl;
                break;
            case 6:
                cout<< chems[index].description << endl << endl << "Molar Mass: " << chems[index].properties[0] << " g/mol" << endl
                << "Melting Point: " << chems[index].properties[1] << " K" << endl << "Boiling Point: " << chems[index].properties[2] << " K" << endl
                << "Critical Temperature: " << chems[index].properties[3] << " K" << endl << "Critical Pressure: " << chems[index].properties[4] << " bar" << endl;
                break;
        }
        cout << endl;
    }
}

void chemicalDatabase::vaporPressure(){
    double Pstar;
    string chemical;
    int again = 1;
    int index = 0;
    int match = 0;
    double temp;
    do{
        cout << "Enter the name of the chemical you would like to find the vapor pressure of." << endl;
        cin >> chemical;
        for(int i=0; i<=chems.size()-1; i++){
            if(chemical == chems[i].name){
                match = 1;
                index = i;
                again = 0;
            }
        }
        if(match == 0){
            cout << "No chemical with the name " << chemical << " could be found." << endl << "Would you like to try again?" << endl
            << "Enter 0 for No and 1 for Yes." << endl;
                do{
                    cin >> again;
                    if(again<0 | again>1){
                        cout << "Enter 0 for No and 1 for Yes." << endl;
                    }
                }
                while(again<0 | again>1);
        }
    }
    while(again == 1);
    if(match == 1){
        double A = chems[index].antoine[0]; double B = chems[index].antoine[1]; double C = chems[index].antoine[2];
        cout << "Enter the temperature in Kelvin at which you would like to find the vapor pressure of " << chemical << "." << endl;
        cin >>  temp;
        Pstar = pow(10,A-(B/(temp+C)));
        cout << "Vapor Pressure of " << chemical << " at " << temp << " K: "<< endl << Pstar << " bar" << endl << endl;
    }
}

double chemicalDatabase::stockAccess(string chemical){
    int index = 0;
    int match = 0;
    for(int i=0; i<=chems.size()-1; i++){
        if(chemical == chems[i].name){
            match = 1;
            index = i;
        }
    }
    if(match == 1){
        return chems[index].properties[0];
    }
    else{
        return 0;
    }
}

void stockRoom::addremove(chemicalDatabase &d){
    int again = 1;
    string chemical;
    double mm = 0;
    double newkg;
    double kgadd;
    double newmol;
    int index = -1;
    do{
        cout << "Enter the name of the chemical of which you would like to add or remove stock." << endl;
        cin >> chemical;
        mm = d.stockAccess(chemical);
        if(mm != 0){
            again = 0;
        }
        else{
            cout << "The chemical you add or remove stock to must be in the database first." << endl;
        }
    }
    while(again == 1);
    int already = 0;
    if(stocks.size()>=1){
        for(int i=0; i<=stocks.size()-1; i++){
            if(stocks[i].name == chemical)
            already = 1;
            index = i;
        }
        if(stocks[0].name == chemical){
            already = 1;
            index = 0;
        }
    }
    cout << "How much of " << chemical << " would you like to add or remove.\nEnter a value in kilograms, use a negative number to remove stock" << endl;
    cin >> kgadd;
    if(already == 0){
        stock Snew;
        Snew.name = chemical;
        Snew.amountkg = kgadd; Snew.amountmoles = kgadd*1000/mm;
        stocks.push_back(Snew);
        index = stocks.size()-1;
    }
    else{
        newkg = kgadd + stocks[index].amountkg;
    newmol = kgadd*1000/mm + stocks[index].amountmoles;
        stocks[index].amountkg = newkg;
        stocks[index].amountmoles = newmol;
    }
    if (stocks[index].amountkg <= 0){
        int remove = 0;
        cout << "There is no more " << chemical << " in stock. Would you like to remove it from the stock room?" << endl
        << "Enter 0 for No and 1 for Yes." << endl;
        cin >> remove;
        if(remove == 1){
            if(stocks.size()==1){
                stocks.clear();
            }
            else{
                for(int k=index; k<=stocks.size()-2; k++){
                    stocks[k] = stocks[k+1];
            }
                stocks.pop_back();
                cout << chemical << " has been removed from the stockroom." << endl;
            }
        }
        else{
            stocks[index].amountkg = 0;
            stocks[index].amountmoles = 0;
        }
    }
    else{
    cout << "You now have " << stocks[index].amountkg << " kg, or " << stocks[index].amountmoles << " moles of " << chemical << " left." << endl << endl;
    }
}

void stockRoom::showStock(){
    if(stocks.size()<1){
        cout << "Stockroom is empty, add stock of a chemical first." << endl;
    }
    else{
        cout << "Current Stock:" << endl;
        for(int i=0; i<=stocks.size()-1; i++){
            cout << stocks[i].name << ":    " << stocks[i].amountkg << " kg        " << stocks[i].amountmoles << " moles" << endl;
        }
        cout << endl;
    }
}