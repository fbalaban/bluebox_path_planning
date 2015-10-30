/*
 * earth_model.h
 *
 *  Created on: Sep 5, 2015
 *      Author: leopoldo
 */

#ifndef EARTH_MODEL_H_
#define EARTH_MODEL_H_

#include <fparams.h>

position_llh startllhCoord();

position_llh ecefTollh(position_ecef inputPos);

position_ecef llhToecef(position_llh inputPos);







#endif /* EARTH_MODEL_H_ */
