#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor
{
private:
    string document;
    stack<string> undoStack;
    stack<string> redoStack;

public:

    void type(string word)
    {
        
        undoStack.push(document);

       
        if (document.empty())
            document = word;
        else
            document = document + " " + word;

       
        while (!redoStack.empty())
        {
            redoStack.pop();
        }
    }

    void undo()
    {
        if (undoStack.empty())
        {
            return;
        }

        
        redoStack.push(document);

     
        document = undoStack.top();
        undoStack.pop();
    }

    void redo()
    {
        if (redoStack.empty())
        {
            return;
        }

       
        undoStack.push(document);

      
        document = redoStack.top();
        redoStack.pop();
    }

    void print()
    {
        cout << "Document: " << document << endl;
    }
};

int main()
{
    TextEditor editor;

    editor.type("Hello");
    editor.print();

    editor.type("World");
    editor.print();

    editor.undo();
    editor.print();

    editor.redo();
    editor.print();

    editor.undo();
    editor.print();

    editor.type("There");
    editor.print();

    editor.redo();
    editor.print();

    return 0;
}
