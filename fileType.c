//
// Created by Wen on 2018/2/22.
//

/**
 *
 * 文件夹也是一种文件，其中保存了文件夹的名字，以及目录其中的文件列表，unix提供了对其打开、读、定位、关闭等操作的函数，但是没有写
 *  读取文件属性 通过stat来获取
 *
 *  所有的文件都有所有者，所有者都有组
 *
 *
 *  *****文件类型分为:普通文件、目录文件、socket文件、符号链接文件、命名管道文件(name pipe)、设备文件
 *
 *     文件类型只要创建了，就不能再更改。每个文件都有9位许可权限和3位特殊权限
 *
 *
 *     普通文件、目录文件、命名管道 的大小是根据它们实际大小决定，文件的大小会跟随内容的增加减少而变化
 *     每个文件都有三个时间：最后修改时间，最后访问时间、权限最后修改时间，修改前两个时间通过调用utime()这个函数来完成，shell可以通过touch 来修改
 *
 *
 *
 *
 */
