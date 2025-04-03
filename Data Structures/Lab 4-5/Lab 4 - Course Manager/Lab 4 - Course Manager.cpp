/*******************************************************
 * Program Name: Paul Barrionuevo
 * Author: Paul Barrionuevo
 * Date: 11/2/2024
 * Description: Course Manager allows you to manipulate the data 
 * from your courses and navigate different options
 * such as sorting or searching.
 *******************************************************/
#include <iostream>
#include "CourseMenu.h"

int main()
{
    FacultyManager facultyManager;
    facultyManager.printAll();
    CourseMenu courseMenu;
    courseMenu.activate();

    return 0;


}