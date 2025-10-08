
import numpy as np
from numpy import nan, inf

add_legend_handle = [
    'Data',
    'pp200GeV.yoda'
]

xpoints = {
    'Data' : [0.25, 0.75, 1.25, 1.75],
    'pp200GeV.yoda' : [0.25, 0.75, 1.25, 1.75],
}
xedges = {
    'Data' : [0.0, 0.5, 1.0, 1.5, 2.0],
    'pp200GeV.yoda' : [0.0, 0.5, 1.0, 1.5, 2.0],
}
ref_xerrs = [
  [abs(xpoints['Data'][i]   - xedges['Data'][i]) for i in range(len(xpoints['Data']))],
  [abs(xedges['Data'][i+1] - xpoints['Data'][i]) for i in range(len(xpoints['Data']))]
]

yvals = {
    'Data' : [2.89, 7.722, 5.5, 3.886],
    'pp200GeV.yoda' : [0.0, 0.0, 0.0, 0.0],
}
xerrs = {
    'Data' : [
        [0.25, 0.25, 0.25, 0.25],
        [0.25, 0.25, 0.25, 0.25],
    ],
    'pp200GeV.yoda' : [
        [0.25, 0.25, 0.25, 0.25],
        [0.25, 0.25, 0.25, 0.25],
    ],
}
yerrs = {
    'Data' : [
        [0.633060028749249, 0.8768774144656709, 1.0580477304923441, 0.6335203232730581],
        [0.633060028749249, 0.8768774144656709, 1.0580477304923441, 0.6335203232730581],
    ],
    'pp200GeV.yoda' : [
        [0.0, 0.0, 0.0, 0.0],
        [0.0, 0.0, 0.0, 0.0],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'Data' : [1.0, 1.0, 1.0, 1.0],
    'pp200GeV.yoda' : [0.0, 0.0, 0.0, 0.0],
}
ratio0_yerrs = {
    'Data' : [
        [0.21905191306202387, 0.11355573872904311, 0.19237231463497165, 0.1630263312591503],
        [0.21905191306202387, 0.11355573872904311, 0.19237231463497165, 0.1630263312591503],
    ],
    'pp200GeV.yoda' : [
        [0.0, 0.0, 0.0, 0.0],
        [0.0, 0.0, 0.0, 0.0],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}