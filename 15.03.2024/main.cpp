#include "AppManager.h"

int main()
{
    AppManager app("index.xml");
    app.showAll();
    app.addUser(User(2, "Leisa", "Adams", "ld134@dropbox.ru", "password"));
    app.showAll();
    app.removeUserById(2);
    app.showAll();
}