# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))

# -- Project information -----------------------------------------------------

project = 'tettigoniidae'
copyright = '2022, N.S. Oblath'
author = 'N.S. Oblath'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'breathe',
    'exhale'
]

# Setup the breathe extension
breathe_projects = {
    "tettigoniidae": "../build/_doxygen/xml"
}
breathe_default_project = "tettigoniidae"

# Setup the exhale extension
exhale_args = {
    # These arguments are required
    "containmentFolder":     "./api",
    "rootFileName":          "library_root.rst",
    "doxygenStripFromPath":  "..",
    # Heavily encouraged optional argument (see docs)
    "rootFileTitle":         "tettigoniidae API",
    # Suggested optional arguments
    "createTreeView":        True,
    # TIP: if using the sphinx-bootstrap-theme, you need
    # "treeViewIsBootstrap": True,
    "exhaleExecutesDoxygen": True,
    "exhaleDoxygenStdin":    """
        INPUT = ../../Library
        INCLUDE_PATH = ../../nymph/Scarab/library/utility ../../nymph/Scarab/library/logger ../../nymph/Cpp/Library/Utility ../../nymph/Cpp/Library/Processor ../build/_cmake/nymph/Scarab/library/utility
        ALIASES += proctype="\\xrefitem processors \\\"Processor\\\" \\\"Processors\\\"" 
        ALIASES += procdetails="\details \par Processor Details"
        ALIASES += config="\par Processor Configuration"
        ALIASES += configparam{2}="<tt>\\1</tt>: (<tt>\\2</tt>) "
        ALIASES += signals="\par Signals"
        ALIASES += signal{2}="<tt>\\1</tt> [<tt>\\2</tt>]: "
        ALIASES += slots="\par Slots"
        ALIASES += slot{2}="<tt>\\1</tt> [<tt>\\2</tt>]: "
    """,
    "verboseBuild": True
}

# Tell sphinx what the primary language being documented is.
primary_domain = 'cpp'

# Tell sphinx what the pygments highlight language should be.
highlight_language = 'cpp'

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

# Favicon
html_favicon = '_static/katydid_logo_favicon.ico'

def setup(app):
    import os, subprocess

    # Run CMake to have access to configured header files
    cmake_path = "build/_cmake"
    os.makedirs(cmake_path, exist_ok=True)
    subprocess.run(["cmake", "../../.."], cwd=cmake_path)
