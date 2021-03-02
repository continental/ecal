.. include:: include.txt

=====================
eCAL Download Archive
=====================

Here you can find a list of all eCAL Versions ever released on GitHub.

@[for release_branch in reversed(download_pages)]@
eCAL @(release_branch.major).@(release_branch.minor)
============

.. toctree::
   :maxdepth: 0
   :titlesonly:

@[    for ecal_version in reversed(download_pages[release_branch])]@
   @(download_pages[release_branch][ecal_version])
@[end for]

@[end for]@