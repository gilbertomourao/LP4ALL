from distutils.core import setup, Extension
import glob

c_files = [file for file in glob.glob("core/*.c", recursive = True)]

module1 = Extension(
    'pylinp', # name
    # define_macros = [('PY_SSIZE_T_CLEAN', None)],
    # it's not necessary to put the Python lib here, because it's already on the PATH
    sources = c_files,
    # extra_compile_args = ['-lliblinp'],
    # extra_link_args = ['-lliblinp'],
    )

setup(
    name = 'pylinp',
    version = '1.0.0',
    description = 'Python version of linp!',
    author = 'Gilberto Jose Guimaraes de Sousa Mourao',
    author_email = 'gilbertojos.mourao@gmail.com',
    url = 'nothing here',
    platforms = 'Windows 10',
    long_description = 'Biblioteca desenvolvida para o aprendizado de linguagem de programação.',
    ext_modules = [module1],
    );