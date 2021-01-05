//
//  Basic.cpp
//  C++Demo
//
//  Created by lieon on 2021/1/4.
//  Copyright © 2021 lieon. All rights reserved.
//

#include "Basic.hpp"
/**
 # 2D笛卡尔坐标系
 - 笛卡尔坐标由一个x坐标和一个y坐标构成。x坐标测量水平方向的位置，y坐标测量垂直方向的位置
 ## 裁剪区域
 - 即在笛卡尔坐标系中的某一块区域，在OpenGL中，窗口是以像素为单位进行度量的，开始在窗口中绘制点线和形状之前，必须告诉OpenGL如何把指定的坐标翻译为屏幕坐标。可以通过指定占据窗口的笛卡尔空间区域完成这个任务，这个区域称为裁剪区域
 ## 视口：把绘图坐标映射到窗口坐标
 - 裁剪区域的宽度和高度很少正好与窗口的宽度和高度相匹配。因此，坐标系统必须从逻辑笛卡尔坐标映射到屋里屏幕像素坐标。这个映射是通过一种叫做视口的设置来指定。视口就是窗口内部用于绘制裁剪区域的客户区域。视口简单地把裁剪区域映射到窗口的一个区域，通常视口被定义为整个窗口。我们可以使用视口来缩小或放大窗口中的图像，如果是视口设置为大于窗口的用户区域，则只显示裁剪区域的一部分
 
 ## 顶点：空间中的一个位置
 - 图元：一维或二维的实体或表面，如点，直线和多边形
 - 在3D空间中，图元组合在一起创建3D物体，例如一个三维立方体是由6个二维的正方形组成，每个正方形代表一个独立的面。正方形的每个角称为顶点。顶点其实也就是2D或者3D空间中的一个坐标
 ###3D笛卡尔坐标系
 
 ## 投影：从3D到2D，用于创建几何图形的3d坐标将投影到一个2d表面；。
 */
