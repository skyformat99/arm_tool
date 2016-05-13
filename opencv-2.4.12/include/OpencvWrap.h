#ifndef __OPENCV_WRAP_05260305_H_
#define __OPENCV_WRAP_05260305_H_
// ˵��:
// ��������0��ʾ�ɹ�������ֵʧ��

#define OPENCV_WRAP_MAX_RULE_NUMBER		128

enum OPENCV_WRAP_DIRECTION{
	OPENCV_WRAP_DIRECTION_LEFT		= 0,
	OPENCV_WRAP_DIRECTION_RIGHT		= 0,
	OPENCV_WRAP_DIRECTION_TOP		= 0,
	OPENCV_WRAP_DIRECTION_BOTTOM		= 0,
};

struct WarningLine {
	int	id;
	int	enable;
	int	warning;
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
};

class COpenCVWrap
{
public:
	// ��ȡ��ʵ������
	static COpenCVWrap* getInstance();

public:
	// ����ӿ�
	int init();
	int setline(struct WarningLine *line);
	bool processimage(void *imagebuffer, int width, int height, struct WarningLine *linearray[]);

private:
	COpenCVWrap(){}
	~COpenCVWrap(){}
};

#endif

