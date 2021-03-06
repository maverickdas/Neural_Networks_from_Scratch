// *************************************************************
// Author: Abhirup Das
// Github: https://github.com/codebuddha
// LinkedIn: https://www.linkedin.com/in/abhirup-das-5a174212a/
// *************************************************************
#include <arrayfire.h>
#include <af/util.h>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <string>
using std::vector;
using std::string;

class Layer
{
public:
	static std::unordered_map<string, std::pair<af::array(*)(const af::array&), af::array(*)(const af::array&)>> activ_map;
	af::array (*activ_fn)(const af::array&), (*activ_deriv_fn)(const af::array&);
	af::array layer;
	Layer(){};
	Layer(int batch_size, int neurons, string activ);
	//activation functions
	static af::array lin_activation(const af::array &x); 
	static af::array lin_deriv_activation(const af::array &x);
	static af::array tanh_activation(const af::array &x);
	static af::array tanh_deriv_activation(const af::array &x);
	static af::array sigm_activation(const af::array &x);
	static af::array sigm_deriv_activation(const af::array &x);
	static af::array relu_activation (const af::array &x);
	static af::array relu_deriv_activation (const af::array &x);

    static void setNewActivation(af::array(*activ)(const af::array&), af::array(*deriv)(const af::array&), string name);
};
std::unordered_map<string, std::pair<af::array(*)(const af::array&), af::array(*)(const af::array&)>> Layer::activ_map =
	{
		{"tanh", std::make_pair(&tanh_activation, &tanh_deriv_activation)},
		{"sigmoid", std::make_pair(&sigm_activation, &sigm_deriv_activation)},
		{"linear", std::make_pair(&lin_activation, &lin_deriv_activation)},
		{"none", std::make_pair(&lin_activation, &lin_deriv_activation)},
		{"relu", std::make_pair(&relu_activation, &relu_deriv_activation)}
	};
Layer::Layer(int b_size, int n, string activ)
{
	layer = af::array(b_size, n);
	activ_fn = activ_map[activ].first;// assigning the chosen activation function to the Layer
	activ_deriv_fn = activ_map[activ].second;
}
af::array Layer::lin_activation(const af::array &x)
{
    return x;
}
af::array Layer::lin_deriv_activation(const af::array &x)
{
    return af::constant(1.0, x.dims());
}
af::array Layer::tanh_activation(const af::array &x)
{
    return af::tanh(x);
}
af::array Layer::tanh_deriv_activation(const af::array &x)
{
    return 1 - (x*x);
}
af::array Layer::sigm_activation(const af::array &x) 
{
    return af::sigmoid(x);
}
af::array Layer::sigm_deriv_activation(const af::array &x)
{
    return x*(1.0 - x);
}
af::array Layer::relu_activation (const af::array &x)
{
    af::array y = x;
    y(af::where(y<0)) = 0;
    return y;
}
af::array Layer::relu_deriv_activation(const af::array &x)
{
    af::array y = x;
    y(af::where(y<0)) = 0.000005;
    y(af::where(y==0)) = 0.005;
    y(af::where(y>0)) = 1.0;
    return y;
}
void Layer::setNewActivation(af::array(*activ)(const af::array&), af::array(*deriv)(const af::array&), string name)
{
    activ_map.insert(std::make_pair(name, std::make_pair(activ, deriv)));
}
