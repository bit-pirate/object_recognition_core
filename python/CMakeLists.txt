if (ROS_GROOVY_OR_ABOVE_FOUND)
configure_file(__init__.py.plain.in
               ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION}/boost/__init__.py
               @ONLY
)
configure_file(__init__.py.plain.in
               ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION}/ecto_cells/__init__.py
               @ONLY
)

install(FILES ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION}/boost/__init__.py
        DESTINATION ${CATKIN_PACKAGE_PYTHON_DESTINATION}/boost
)
install(FILES ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION}/ecto_cells/__init__.py
        DESTINATION ${CATKIN_PACKAGE_PYTHON_DESTINATION}/ecto_cells
)
else()

configure_file(__init__.py.plain.in
               ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_BUILD_DESTINATION}/boost/__init__.py
               @ONLY
)
configure_file(__init__.py.plain.in
               ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_BUILD_DESTINATION}/ecto_cells/__init__.py
               @ONLY
)
install(FILES ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_BUILD_DESTINATION}/boost/__init__.py
        DESTINATION ${CATKIN_PACKAGE_PYTHON_DESTINATION}/boost
)
install(FILES ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_BUILD_DESTINATION}/ecto_cells/__init__.py
        DESTINATION ${CATKIN_PACKAGE_PYTHON_DESTINATION}/ecto_cells
)
endif()
