/**
* @file NexScreen.h
*
* The definition of class NexScreen.
*
* @author kosza (email:<koszab@gmail.com>)
* @date 2016/9/16
*
* @copyright
*/

#ifndef __NEXSCREEN_H__
#define __NEXSCREEN_H__

#include "NexTouch.h"
#include "NexHardware.h"
/**
* @addtogroup Component
* @{
*/

/**
 * Type of callback funciton when an touch event occurs. 
 *  
 * @return none. 
 */
typedef void (*NexScreenEventCb)();

/**
* NexScreen component.
*
*
*/
class NexScreen : public NexObject
{
public: /* static methods */        
	static void eventCallback(void);

public: /* methods */

	/**
	* @copydoc NexTouch::NexTouch(0, 0, "screen");
	*/
	NexScreen();
	
	void attachCallback(byte event, NexScreenEventCb callback);
	/**
	* Set the brightness of the display.
	*
	* @param buffer - number (0 - 100).
	*/
	bool setBrightness(byte buffer);
	/**
	* Set Nextion sleep mode.
	*/
	bool Sleep();
	/**
	* Set Nextion awake mode.
	*/
	bool Wakeup();
	/**
	* Set Auto Wake on Touch.
	*
	* @param buffer - number, 0 (do not wake), 1 (wake on touch), default 0.
	*/
	bool setAutoWakeup(byte buffer);
	/**
	* Set Sleep on No Touch.
	*
	* @param buffer - number of second, 3 - 65535, default 0 (means no timeout)
	*/
	bool setScreenTouchTimeout(int buffer);	

private: /* methods */ 
    

private: /* data */ 
    NexScreenEventCb __cb_event;    
};

/**
* @}
*/


#endif /* #ifndef __NEXSCREEN_H__ */