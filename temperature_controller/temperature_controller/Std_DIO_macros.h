#define REGISTER_SIZE          8
#define SET_BIT(reg,bit)       reg|=(1<<bit) 
#define CLR_BIT(reg,bit)       reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)       reg^=(1<<bit)
#define READ_BIT(reg,bit)      ((reg>>bit)&1)
#define IS_BIT_SET(reg,bit)    ((reg>>bit)&1)
#define IS_BIT_CLR(reg,bit)    !((reg>>bit)&1)
#define ROR(reg,num)           reg=((reg>>num)|(reg<<(REGISTER_SIZE-num)))
#define ROL(reg,num)           reg=((reg<<num)|(reg>>(REGISTER_SIZE-num)))

