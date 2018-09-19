#include "Block.h"



Block::Block()
{
	setRect(0, 0, blockSize, blockSize);
	QBrush brush_block(QImage("Resources/Block.png"));//设置障碍物样式
	setBrush(brush_block);
}

Block::~Block()
{

}
