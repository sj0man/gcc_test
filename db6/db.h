#include "int.h"


#define NUM_DB6_CH		(32)

#define		SIZE_DB_TEXT			256

#define		SIZE_TEXTIN_STR			2000

#define		MIRROR_MIN_SIZE			(50*1024*1024)

#define		ROOTFS_DIR			"/"
#define		SD_MOUNT			"data"
#define		DATA_DIR			ROOTFS_DIR SD_MOUNT


#define SECS_IN_MIN			(60)
#define SECS_IN_HOUR		(60*SECS_IN_MIN)
#define SECS_IN_DAY			(24*SECS_IN_HOUR)

#define MINS_IN_CHUNK		(10)
#define SECS_IN_CHUNK		(MINS_IN_CHUNK*SECS_IN_MIN)
#define NUM_CHUNK			(SECS_IN_DAY / SECS_IN_CHUNK)

// 시간 관련..
#define SECS2HH(secs)		((secs)/SECS_IN_HOUR)
#define SECS2MM(secs)		(((secs)/SECS_IN_MIN)%60)
#define SECS2SS(secs)		((secs)%SECS_IN_MIN)
#define HHMMSS2SECS(hh, MM, ss)		((hh)*3600 + (MM)*60 + ss)
#define HHMMSS2CHUNK(hh, MM, ss)	(((hh)*3600 + (MM)*60 + ss)/SECS_IN_CHUNK)

#define CHUNK2HH(chunk)		(((chunk)*MINS_IN_CHUNK)/60)
#define CHUNK2MM(chunk)		(((chunk)*MINS_IN_CHUNK)%60)


typedef enum
{
	EL6_TYPE_REC_CH01		= 0x000,
	EL6_TYPE_SEN_CH01		= 0x020,
	EL6_TYPE_MD_CH01		= 0x040,
	EL6_TYPE_VL_CH01		= 0x060,
	EL6_TYPE_TEXTIN_CH01	= 0x080,
	EL6_TYPE_VA_CH01		= 0x0A0,		// VA ==> Video Analisys
	EL6_TYPE_VD_CH01		= 0x0C0,		// VD ==> Variable Data
	EL6_TYPE_USER3_CH01		= 0x0E0,
	EL6_TYPE_USER4_CH01		= 0x100,
	NUM_EL6_TYPE			= 0x120
} EL6_TYPE;





typedef struct db6_head_s {
	__u32	magic;			///< magic
	__u16	version;		///< 버전
	__u16	rev;			///< 리비전

	__u32	num_day;		///< db6_date_t 전체 갯수
	__u32	off_date;		///< 맨 처음 db6_date_t 위치
	__u32	off_free_date;	///< 사용하지 않은 db6_date_t 위치

	__u32	reserved;		///< 추후 사용을 위한 예비
} db6_head_t;


typedef struct db6_date_s {
	__u32	magic;					///< DB6_MAGIC ==> 보통 verify 를 위해서 넣는다.
	__u32	id;						///< 해당 날짜의 id 번호, 해당 폴더에 생성되는 폴더 번호와 일치함.. 1 ~ 4G까지
	__u32	off_next;				///< 퍄일 내에서 다음 db6_data_s 의 위치를 가리킴

	__u16	year;					///< 년
	__u8	month;					///< 월
	__u8	mday;					///< 일

	__u32	num_el[NUM_EL6_TYPE];	///< 이벤트 리스트 전체 갯수

	/// @brief chunk 의 간단한 정보  ///
	struct {
		__u8	hdd:6;				///< 저장되어 있는 hdd 인덱스
		__u8	valid:1;			///< 유효
		__u8	bookmark:1;			///< 삭제방지용 데이타 유무
	} chunk[NUM_CHUNK];

	__u64	rec[NUM_DB6_CH][24];	//  채널별, 시간/분 별 녹화 정보
	__u64	event[NUM_DB6_CH][24];	// 채널별, 시간/분 별 이벤트 정보

} db6_date_t;
