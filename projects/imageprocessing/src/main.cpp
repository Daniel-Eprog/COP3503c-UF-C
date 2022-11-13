#include "tgaimg.h"
#include <string>

int main()
{
    //Welcome message
    cout << "***************************************************" << endl;
    cout << "* Welcome to Esteban's Immaculate Image Processor *" << endl;
    cout << "*          Images Are Currently Processing        *" << endl;
    cout << "*                 Please Stand By...              *" << endl;
    cout << "***************************************************" << endl;

    /*Part I*/
    TGAimg part1Img1;
    TGAimg part1Img2;
    part1Img2.loadIMG("input/pattern1.tga");
    part1Img1.loadIMG("input/layer1.tga");
    part1Img1.blendMultiply(part1Img2);
    part1Img1.exportIMG("output/part1.tga");

    /*Part II*/
    TGAimg part2Img1;
    TGAimg part2Img2;
    TGAimg testImg2; //EXAMPLE image to test against
    testImg2.loadIMG("examples/EXAMPLE_part2.tga"); //load EXAMPLE image
    part2Img1.loadIMG("input/layer2.tga");
    part2Img2.loadIMG("input/car.tga");
    part2Img1.blendSubtract(part2Img2);
    part2Img1.exportIMG("output/part2.tga");

    /*Part III*/
    TGAimg part3Img1;
    TGAimg part3Img2;
    TGAimg part3Img3;
    TGAimg testImg3;
    testImg3.loadIMG("examples/EXAMPLE_part3.tga");
    part3Img1.loadIMG("input/layer1.tga");
    part3Img2.loadIMG("input/pattern2.tga");
    part3Img3.loadIMG("input/text.tga");
    part3Img1.blendMultiply(part3Img2);
    part3Img3.blendScreen(part3Img1);
    part3Img3.exportIMG("output/part3.tga");

    /*Part IV*/
    TGAimg part4Img1;
    TGAimg part4Img2;
    TGAimg part4Img3;
    part4Img1.loadIMG("input/layer2.tga");
    part4Img2.loadIMG("input/circles.tga");
    part4Img3.loadIMG("input/pattern2.tga");
    part4Img2.blendMultiply(part4Img1);
    part4Img3.blendSubtract(part4Img2);
    part4Img3.exportIMG("output/part4.tga");

    /*PART V*/
    TGAimg part5Img1;
    TGAimg part5Img2;
    part5Img1.loadIMG("input/layer1.tga");
    part5Img2.loadIMG("input/pattern1.tga");
    part5Img1.blendOverlay(part5Img2);
    part5Img1.exportIMG("output/part5.tga");

    /*Part VI*/
    TGAimg part6Img1;
    part6Img1.loadIMG("input/car.tga");
    part6Img1.addGreen(200);
    part6Img1.exportIMG("output/part6.tga");

    /*Part VII*/
    TGAimg part7Img1;
    part7Img1.loadIMG("input/car.tga");
    part7Img1.scaleRed(4);
    part7Img1.scaleBlue(0);
    part7Img1.exportIMG("output/part7.tga");

    /*Part VIII*/
    TGAimg part8r;
    TGAimg part8g;
    TGAimg part8b;
    part8r.loadIMG("input/car.tga");
    part8g.loadIMG("input/car.tga");
    part8b.loadIMG("input/car.tga");
    part8r.separateRed();
    part8b.separateBlue();
    part8g.separateGreen();
    part8r.exportIMG("output/part8_r.tga");
    part8b.exportIMG("output/part8_b.tga");
    part8g.exportIMG("output/part8_g.tga");

    /*Part IX*/
    TGAimg part9Blue;
    TGAimg part9Green;
    TGAimg part9Red;
    part9Blue.loadIMG("input/layer_blue.tga");
    part9Green.loadIMG("input/layer_green.tga");
    part9Red.loadIMG("input/layer_red.tga");
    part9Blue.combineColors(part9Green, part9Red);
    part9Blue.exportIMG("output/part9.tga");

    /*Part X*/
    TGAimg part10img1;
    part10img1.loadIMG("input/text2.tga");
    part10img1.rotateImage();
    part10img1.exportIMG("output/part10.tga");

    cout << "***************************************************" << endl;
    cout << "*                Images Processed :)              *" << endl;
    cout << "*            Testing Images for Fidelity          *" << endl;
    cout << "*                Please Stand By...               *" << endl;
    cout << "***************************************************" << endl;

    /*Load Test Images*/
    TGAimg test1;
    TGAimg test2;
    TGAimg test3;
    TGAimg test4;
    TGAimg test5;
    TGAimg test6;
    TGAimg test7;
    TGAimg test8b;
    TGAimg test8g;
    TGAimg test8r;
    TGAimg test9;
    TGAimg test10;
    test1.loadIMG("examples/EXAMPLE_part1.tga");
    test2.loadIMG("examples/EXAMPLE_part2.tga");
    test3.loadIMG("examples/EXAMPLE_part3.tga");
    test4.loadIMG("examples/EXAMPLE_part4.tga");
    test5.loadIMG("examples/EXAMPLE_part5.tga");
    test6.loadIMG("examples/EXAMPLE_part6.tga");
    test7.loadIMG("examples/EXAMPLE_part7.tga");
    test8b.loadIMG("examples/EXAMPLE_part8_b.tga");
    test8g.loadIMG("examples/EXAMPLE_part8_g.tga");
    test8r.loadIMG("examples/EXAMPLE_part8_r.tga");
    test9.loadIMG("examples/EXAMPLE_part9.tga");
    test10.loadIMG("examples/EXAMPLE_part10.tga");

    /*Reload exported images for testing proper export method*/

    TGAimg process1;
    TGAimg process2;
    TGAimg process3;
    TGAimg process4;
    TGAimg process5;
    TGAimg process6;
    TGAimg process7;
    TGAimg process8b;
    TGAimg process8g;
    TGAimg process8r;
    TGAimg process9;
    TGAimg process10;
    process1.loadIMG("output/part1.tga");
    process2.loadIMG("output/part2.tga");
    process3.loadIMG("output/part3.tga");
    process4.loadIMG("output/part4.tga");
    process5.loadIMG("output/part5.tga");
    process6.loadIMG("output/part6.tga");
    process7.loadIMG("output/part7.tga");
    process8b.loadIMG("output/part8b.tga");
    process8g.loadIMG("output/part8g.tga");
    process8r.loadIMG("output/part8r.tga");
    process9.loadIMG("output/part9.tga");
    process10.loadIMG("output/part10.tga");
    
    if(test1.compareIMG(process1))
    {
        cout << "Test 1: Success!" << endl;
    }
    else
    {
        cout << "Test 1: Fail!" << endl;
    }
     if(test2.compareIMG(process2))
    {
        cout << "Test 2: Success!" << endl;
    }
    else
    {
        cout << "Test 2: Fail!" << endl;
    }
    if(test3.compareIMG(process3))
    {
        cout << "Test 3: Success!" << endl;

    }
    else 
    {
        cout << "Test 3: Fail!" << endl;
    }
    if(test4.compareIMG(process4))
    {
        cout << "Test 4: Success!" << endl;

    }
    else 
    {
        cout << "Test 4: Fail!" << endl;
    }
    if(test5.compareIMG(process5))
    {
        cout << "Test 5: Success!" << endl;

    }
    else 
    {
        cout << "Test 5: Fail!" << endl;
    }
    if(test6.compareIMG(process6))
    {
        cout << "Test 6: Success!" << endl;

    }
    else 
    {
        cout << "Test 6: Fail!" << endl;
    }
    if(test7.compareIMG(part7Img1))
    {
        cout << "Test 7: Success!" << endl;

    }
    else 
    {
        cout << "Test 7: Fail!" << endl;
    }
    if(test8b.compareIMG(part8b) && test8g.compareIMG(part8g) && test8r.compareIMG(part8r))
    {
        cout << "Test 8: Success!" << endl;
    }
    else 
    {
        cout << "Test 8: Fail!" << endl;
    }
     if(test9.compareIMG(part9Blue))
    {
        cout << "Test 9: Success!" << endl;

    }
    else 
    {
        cout << "Test 9: Fail!" << endl;
    }
     if(test10.compareIMG(part10img1))
    {
        cout << "Test 10: Success!" << endl;

    }
    else 
    {
        cout << "Test 10: Fail!" << endl;
    }


     return 0;
}
