//BAD Design
#include<bits/stdc++.h>
using namespace std;

class documentEditor{
    vector<string>elements;
    string renderedDocument;
    public:
    void addText(string text){
        elements.push_back(text);
    }
    void addImage(string path){
        elements.push_back(path);
    }
    string renderDocument() {
        if(renderedDocument.empty()) {
            string result;
            for (auto element : elements) {
                if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" ||
                 element.substr(element.size() - 4) == ".png")) {
                    result += "[Image: " + element + "]" + "\n";
                } else {
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }
    void saveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file<<renderDocument();
            file.close();
            cout<<"Document is saved to document.txt"<<endl;
        }else{
            cout<<"Error to open file"<<endl;
        }
    }
};

int main(){
    documentEditor editor;
    editor.addText("Hello World");
    editor.addImage("picture.jpg");
    editor.renderDocument();
    editor.saveToFile();
    return 0;
}