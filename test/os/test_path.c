#include "../lib/runner.h"

#include "../../src/uv_os.h"

TEST_MODULE(path);

/* Join a directory path and a filename into a full path. */
TEST_CASE(join, NULL)
{
    const uvDir dir = "/foo";
    const uvFilename filename = "bar";
    uvPath path;
    (void)data;
    (void)params;
    osJoin(dir, filename, path);
    munit_assert_string_equal(path, "/foo/bar");
    return MUNIT_OK;
}

/* Extract the directory name from a full path. */
TEST_CASE(dirname, NULL) {
    const uvPath path = "/foo/bar";
    uvDir dir;
    (void)data;
    (void)params;
    uvDirname(path, dir);
    munit_assert_string_equal(dir, "/foo");
    return MUNIT_OK;
}
