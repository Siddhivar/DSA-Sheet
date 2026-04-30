#include<bits/stdc++.h>
using namespace std;

//Abstract Products
class Button{
    public:
    virtual void paint()=0;
};
class Checkbox{
    public:
    virtual void paint()=0;
};

//Concrete Products
class WindowsButton:public Button{
    public:
    void paint()override{
        cout<<"Windows Button"<<endl;
    }
};
class MacOSButton:public Button{
    public:
    void paint()override{
        cout<<"MacOS Button"<<endl;
    }
};
class WindowsCheckbox:public Checkbox{
    public:
    void paint()override{
        cout<<"Windows Checkbox"<<endl;
    }
};
class MacOSCheckbox:public Checkbox{
    public:
    void paint()override{
        cout<<"MacOS Checkbox"<<endl;
    }
};

//Abstract Factory
class GUIFactory{
    public:
    virtual Button* createbutton()=0;
    virtual Checkbox* createCheckbox()=0;
};

//Concrete Factories
class WindowsGUIFactory:public GUIFactory{
    public:
    Button* createbutton()override{
        return new WindowsButton(); 
    }
    Checkbox* createCheckbox()override{
        return new WindowsCheckbox();
    }
};
class MacOSGUIFactory: public GUIFactory{
    public:
    Button* createbutton()override{
        return new MacOSButton(); 
    }
    Checkbox* createCheckbox()override{
        return new MacOSCheckbox();
    }
};

int main(){
    string OS="Windows";
    GUIFactory* factory;
    if(OS=="Windows"){
        factory= new WindowsGUIFactory;
    }else{
        factory= new MacOSGUIFactory;
    }
    Button* b=factory->createbutton();
    Checkbox* c=factory->createCheckbox();
    b->paint();
    c->paint();
    return 0;
}
/*👉 Client never does: new WindowsButton()
👉 It only does: factory->createButton()
Factory decides which family
All objects come from same family
No mixing possible
*/