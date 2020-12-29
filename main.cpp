#include <iostream>

void demo0()
{
    float F[] = {1,2,3,4,5,6,7,8,9};
    float K[] = {1,2,3,4,5,6,7,8,9};
    float O = 0;

    int width  = 3;
    int height = 3;
    int kSizeX = 3;
    int kSizeY = 3;

    for(int m=0;m<kSizeY;m++)
    {
        for(int n=0;n<kSizeX;n++)
        {
            O+=K[m*kSizeX+n]*F[m*width+n];
        }
    }
    std::cout<<O<<" ";
}

void demo1()
{
    // (height + 2 * paddingY - (dilationY * (kSizeY - 1) + 1)) / strideY + 1;
    // (width + 2 * paddingX - (dilationX * (kSizeX - 1) + 1)) / strideX + 1;

    float F[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    float K[] = {1,2,3,4,5,6,7,8,9};
    float O[] = {0,0,0,0};

    int padX = 0;
    int padY = 0;

    int dilationX = 1;
    int dilationY = 1;

    int strideX  = 1;
    int strideY  = 1;

    int width = 4;
    int height = 4;

    int kSizeX = 3;
    int kSizeY = 3;

    int outH = (height+2*padY-(dilationY*(kSizeY-1)+1)) / strideY + 1;
    int outW = (width+2*padX-(dilationX*(kSizeX-1)+1)) / strideX + 1;

    for(int i=0;i<outH;i++)
    {
        for(int j=0;j<outW;j++)
        {
            for(int m=0;m<kSizeY;m++)
            {
                for(int n=0;n<kSizeX;n++)
                {
                    O[i*outW+j]+=K[m*kSizeX+n]*F[(m+i)*width+(n+j)];
                }
            }
        }
    }

    for (int i = 0; i < outH; ++i)
    {
        for (int j = 0; j < outW; ++j)
        {
            std::cout<<O[i*outW+j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void demo2()
{
    // (height + 2 * paddingY - (dilationY * (kSizeY - 1) + 1)) / strideY + 1;
    // (width + 2 * paddingX - (dilationX * (kSizeX - 1) + 1)) / strideX + 1;

    float F[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    float K[] = {1,2,3,4};
    //float K[] = {1,2,3,4,5,6,7,8,9};
    float O[] = {0,0,0,0};

    int padX = 0;
    int padY = 0;

    int dilationX = 1;
    int dilationY = 1;

    int strideX  = 2;
    int strideY  = 2;

    int width = 4;
    int height = 4;

    int kSizeX = 2;
    int kSizeY = 2;

    int outH = (height+2*padY-(dilationY*(kSizeY-1)+1)) / strideY + 1;
    int outW = (width+2*padX-(dilationX*(kSizeX-1)+1)) / strideX + 1;

    for(int i=0;i<outH;i++)
    {
        for(int j=0;j<outW;j++)
        {
            for(int m=0;m<kSizeY;m++)
            {
                for(int n=0;n<kSizeX;n++)
                {
                    O[i*outW+j]+=K[m*kSizeX+n]*F[(m+i*strideY)*width+(n+j*strideX)];
                }
            }
        }
    }

    for (int i = 0; i < outH; ++i)
    {
        for (int j = 0; j < outW; ++j)
        {
            std::cout<<O[i*outW+j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void demo3()
{
    // (height + 2 * paddingY - (dilationY * (kSizeY - 1) + 1)) / strideY + 1;
    // (width + 2 * paddingX - (dilationX * (kSizeX - 1) + 1)) / strideX + 1;

    float F[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    //float K[] = {1,2,3,4};
    float K[] = {1,2,3,4,5,6,7,8,9};
    float O[] = {0,0,0,0};

    int padX = 1;
    int padY = 1;

    int dilationX = 1;
    int dilationY = 1;

    int strideX  = 2;
    int strideY  = 2;

    int width = 4;
    int height = 4;

    int kSizeX = 3;
    int kSizeY = 3;

    int outH = (height+2*padY-(dilationY*(kSizeY-1)+1)) / strideY + 1;
    int outW = (width+2*padX-(dilationX*(kSizeX-1)+1)) / strideX + 1;

    for(int i=0;i<outH;i++)
    {
        for(int j=0;j<outW;j++)
        {
            for(int m=0;m<kSizeY;m++)
            {
                for(int n=0;n<kSizeX;n++)
                {
                    float fVal = 0;
                    //考虑边界强情况
                    if((n+j*strideX-padX)>-1&&(m+i*strideY-padY>-1)&&(n+j*strideX-padX)<=width&&(m+i*strideY-padY>-1)<=height)
                    {
                        fVal = F[(m+i*strideY-padX)*width+(n+j*strideX-padY)];
                    }
                    O[i*outW+j]+=K[m*kSizeX+n]*fVal;
                }
            }
        }
    }

    for (int i = 0; i < outH; ++i)
    {
        for (int j = 0; j < outW; ++j)
        {
            std::cout<<O[i*outW+j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void demo4()
{
    // (height + 2 * paddingY - (dilationY * (kSizeY - 1) + 1)) / strideY + 1;
    // (width + 2 * paddingX - (dilationX * (kSizeX - 1) + 1)) / strideX + 1;

    float F[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    //float K[] = {1,2,3,4};
    float K[] = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};
    float O[] = {0,0,0,0};

    int padX = 1;
    int padY = 1;

    int dilationX = 1;
    int dilationY = 1;

    int strideX  = 2;
    int strideY  = 2;

    int width = 4;
    int height = 4;

    int kSizeX = 3;
    int kSizeY = 3;

    int channel = 2;

    int outH = (height+2*padY-(dilationY*(kSizeY-1)+1)) / strideY + 1;
    int outW = (width+2*padX-(dilationX*(kSizeX-1)+1)) / strideX + 1;

    for (int c = 0; c < channel; ++c)
    {
        for(int i=0;i<outH;i++)
        {
            for(int j=0;j<outW;j++)
            {
                for(int m=0;m<kSizeY;m++)
                {
                    for(int n=0;n<kSizeX;n++)
                    {
                        float fVal = 0;
                        if((n+j*strideX-padX)>-1&&(m+i*strideY-padY>-1)&&(n+j*strideX-padX)<=width&&(m+i*strideY-padY>-1)<=height)
                        {
                            fVal = F[c*width*height + (m+i*strideY-padX)*width+(n+j*strideX-padY)];
                        }
                        O[i*outW+j]+=K[c*kSizeX*kSizeY+m*kSizeX+n]*fVal;
                    }
                }
            }
        }
    }

    for (int i = 0; i < outH; ++i)
    {
        for (int j = 0; j < outW; ++j)
        {
            std::cout<<O[i*outW+j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void demo5()
{
    // (height + 2 * paddingY - (dilationY * (kSizeY - 1) + 1)) / strideY + 1;
    // (width + 2 * paddingX - (dilationX * (kSizeX - 1) + 1)) / strideX + 1;

    float F[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    //float K[] = {1,2,3,4};
    float K[] = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,
                 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9
                };
    float O[] = {0,0,0,0,0,0,0,0};

    int padX = 1;
    int padY = 1;

    int dilationX = 1;
    int dilationY = 1;

    int strideX  = 2;
    int strideY  = 2;

    int width = 4;
    int height = 4;

    int kSizeX = 3;
    int kSizeY = 3;

    int channel = 2;

    int filters = 2;

    int outH = (height+2*padY-(dilationY*(kSizeY-1)+1)) / strideY + 1;
    int outW = (width+2*padX-(dilationX*(kSizeX-1)+1)) / strideX + 1;

    int outC = filters;

    for (int oc = 0; oc < outC; ++oc)
    {
        for (int c = 0; c < channel; ++c)
        {
            for(int i=0;i<outH;i++)
            {
                for(int j=0;j<outW;j++)
                {
                    for(int m=0;m<kSizeY;m++)
                    {
                        for(int n=0;n<kSizeX;n++)
                        {
                            float fVal = 0;
                            if((n+j*strideX-padX)>-1&&(m+i*strideY-padY>-1)&&(n+j*strideX-padX)<=width&&(m+i*strideY-padY>-1)<=height)
                            {
                                fVal = F[c*width*height + (m+i*strideY-padX)*width+(n+j*strideX-padY)];
                            }
                            O[oc*outH*outW+i*outW+j]+=K[oc*outC*kSizeX*kSizeY+c*kSizeX*kSizeY+m*kSizeX+n]*fVal;
                        }
                    }
                }
            }
        }
    }

    for (int oc = 0; oc < outC; ++oc)
    {
        for (int i = 0; i < outH; ++i)
        {
            for (int j = 0; j < outW; ++j)
            {
                std::cout<<O[oc*outH*outW+i*outW+j]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl<<std::endl;
    }
}

void demo6()
{
    // (height + 2 * paddingY - (dilationY * (kSizeY - 1) + 1)) / strideY + 1;
    // (width + 2 * paddingX - (dilationX * (kSizeX - 1) + 1)) / strideX + 1;

    float F[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    //float K[] = {1,2,3,4};
    float K[] = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,
                 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9
                };
    float O[] = {0,0,0,0,0,0,0,0};

    int padX = 1;
    int padY = 1;

    int dilationX = 2;
    int dilationY = 2;

    int strideX  = 1;
    int strideY  = 1;

    int width = 4;
    int height = 4;

    int kSizeX = 3;
    int kSizeY = 3;

    int channel = 2;

    int filters = 2;

    int outH = (height+2*padY-(dilationY*(kSizeY-1)+1)) / strideY + 1;
    int outW = (width+2*padX-(dilationX*(kSizeX-1)+1)) / strideX + 1;

    int outC = filters;

    for (int oc = 0; oc < outC; ++oc)
    {
        for (int c = 0; c < channel; ++c)
        {
            for(int i=0;i<outH;i++)
            {
                for(int j=0;j<outW;j++)
                {
                    for(int m=0;m<kSizeY;m++)
                    {
                        for(int n=0;n<kSizeX;n++)
                        {
                            float fVal = 0;
                            if( ((n+j*strideX)*dilationX-padX)>-1 && ((m+i*strideY)*dilationY-padY)>-1&&
                                    ((n+j*strideX)*dilationX-padX)<=width && ((m+i*strideY)*dilationY-padY>-1)<=height)
                            {
                                fVal = F[c*width*height + ((m+i*strideY)*dilationX-padX)*width+((n+j*strideX)*dilationY-padY)];
                            }
                            O[oc*outH*outW+i*outW+j]+=K[oc*outC*kSizeX*kSizeY+c*kSizeX*kSizeY+m*kSizeX+n]*fVal;
                        }
                    }
                }
            }
        }
    }

    for (int oc = 0; oc < outC; ++oc)
    {
        for (int i = 0; i < outH; ++i)
        {
            for (int j = 0; j < outW; ++j)
            {
                std::cout<<O[oc*outH*outW+i*outW+j]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
}


int main(int argc, char *argv[])
{
    //demo0();
    //demo1();
    //demo2();
    //demo3();
    //demo4();
    //demo5();
    demo6();
}
