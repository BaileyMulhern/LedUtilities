#ifndef EFFECT_H
#define EFFECT_H


/** @class Effect
 *  @brief Virtual class for the creation of LED effects 
 *
 */
class Effect
{
  public:

    Effect(){};

	virtual void reset() = 0;
    virtual void loop() = 0;

};

#endif //EFFECT_H
